using System;
using System.Collections.Generic;
using System.Collections.Specialized;
using System.Configuration;
using System.IO;
using System.Text;

namespace Microsoft.Csi.Hqse.SmartFailures
{
    /// <summary>
    /// Main class containing the smart failures parsing logic
    /// </summary>
    public class SmartFailuresMain
    {
        #region Variables Declaration
        /// <summary>
        /// Space string
        /// </summary>
        public const string space = " ";
        
        /// <summary>
        /// Newline string
        /// </summary>
        public const string newline = "\n";

        /// <summary>
        /// String indicating start of smart failure section
        /// </summary>
        internal readonly string StartInfoSection;

        /// <summary>
        /// String indicating start of attribute section
        /// </summary>
        internal readonly string SmartFailureAttributesSection;
        
        /// <summary>
        /// File path of the input file which contains the failures
        /// </summary>
        internal string InputFilePath { get; set; }

        /// <summary>
        /// Output file where we write the parsed output to be uploaded to Cosmos
        /// </summary>
        internal string OutputFilePath { get; set; }

        /// <summary>
        /// List of failures which are parsed from the text file
        /// </summary>
        internal List<SmartFailures> SmartFailuresList { get; set; }
        #endregion

        #region Constructor
        /// <summary>
        /// Constructor initializing the input and output file paths from
        /// </summary>
        /// <param name="inputFilePath">Input file path containing smart hardware failures information</param>
        /// <param name="outputFilePath">Output file path written with parsed hardware failures</param>
        /// <param name="startInfoSection">String indicating start of smart failure section</param>
        /// <param name="smartFailureAttributeSection">String indicating start of attribute section</param>
        public SmartFailuresMain(string inputFilePath, string outputFilePath, string startInfoSection, string smartFailureAttributeSection)
        {
            InputFilePath = inputFilePath;
            OutputFilePath = outputFilePath;
            StartInfoSection = startInfoSection;
            SmartFailureAttributesSection = smartFailureAttributeSection;

            SmartFailuresList = new List<SmartFailures>();
        }
        #endregion

        #region Methods
        /// <summary>
        /// Method which parses the input text file and extracts the failures into objects
        /// </summary>
        internal void Parse()
        {
            var lines = File.ReadLines(InputFilePath);
            int newStartInfoSection = 0;
            int startInfoSectionCounter = 1;

            SmartFailures sf;
            SmartFailuresProperty sp;
            List<SmartFailuresProperty> spList = new List<SmartFailuresProperty>();
            string[] smartFailureInfo = new string[12];

            foreach (var line in lines)
            {
                if(newStartInfoSection == 3)
                {
                    if (line != string.Empty)
                    {
                        string[] attributes = line.Split(space.ToCharArray(), StringSplitOptions.RemoveEmptyEntries);

                        sp = new SmartFailuresProperty();
                        sp.IdNumber = attributes[0];
                        sp.AttributeName = attributes[1];
                        sp.Flag = attributes[2];
                        sp.Value = attributes[3];
                        sp.Worst = attributes[4];
                        sp.Thresh = attributes[5];
                        sp.Type = attributes[6];
                        sp.Updated = attributes[7];
                        sp.WhenFailed = attributes[8];
                        sp.RawValue = attributes[9];
                        spList.Add(sp);
                        continue;
                    }
                    else
                    {
                        sf = new SmartFailures();
                        sf.DeviceModel = smartFailureInfo[0];
                        sf.SerialNumber = smartFailureInfo[1];
                        sf.LU_WWN_Device = smartFailureInfo[2];
                        sf.FirmwareVersion = smartFailureInfo[3];
                        sf.UserCapacity = smartFailureInfo[4];
                        sf.SectorSizes = smartFailureInfo[5];
                        sf.DeviceIs = smartFailureInfo[6];
                        sf.ATAVersionIs = smartFailureInfo[7];
                        sf.ATAStandardIs = smartFailureInfo[8];
                        sf.LocalTimeIs = smartFailureInfo[9];
                        sf.SmartSupportAvailable = smartFailureInfo[10];
                        sf.SmartSupportEnabled = smartFailureInfo[11];
                        sf.SmartFailuresProperties = spList;

                        SmartFailuresList.Add(sf);

                        newStartInfoSection = 0;
                        continue;
                    }
                }
                else if(newStartInfoSection == 2)
                {
                    if(line.Equals(SmartFailureAttributesSection))
                    {
                        newStartInfoSection = 3;
                        spList = new List<SmartFailuresProperty>();
                    }

                    continue;
                }
                else if (newStartInfoSection == 1)
                {
                    string sfInfoValue = line.Substring(line.IndexOf(':') + 1).Trim();

                    switch(startInfoSectionCounter)
                    {
                        case 1: smartFailureInfo[0] = sfInfoValue;
                            break;
                        case 2: smartFailureInfo[1] = sfInfoValue;
                            break;
                        case 3: smartFailureInfo[2] = sfInfoValue;
                            break;
                        case 4: smartFailureInfo[3] = sfInfoValue;
                            break;
                        case 5: smartFailureInfo[4] = sfInfoValue;
                            break;
                        case 6: smartFailureInfo[5] = sfInfoValue;
                            break;
                        case 7: smartFailureInfo[6] = sfInfoValue;
                            break;
                        case 8: smartFailureInfo[7] = sfInfoValue;
                            break;
                        case 9: smartFailureInfo[8] = sfInfoValue;
                            break;
                        case 10: smartFailureInfo[9] = sfInfoValue;
                            break;
                        case 11: smartFailureInfo[10] = sfInfoValue;
                            break;
                        case 12: smartFailureInfo[11] = sfInfoValue;
                            break;
                        default: 
                            break;
                    }
                    
                    if(startInfoSectionCounter < 12)
                    {
                        startInfoSectionCounter = startInfoSectionCounter + 1;
                        continue;
                    }
                    else
                    {
                        startInfoSectionCounter = 1;
                        newStartInfoSection = 2;
                        continue;
                    }
                }
                else if (newStartInfoSection == 0)
                {
                    if (line.Equals(StartInfoSection))
                    {
                        newStartInfoSection = 1;
                    }

                    continue;
                }
            }
        }

        /// <summary>
        /// Writing the list of smart failures to the output file
        /// </summary>
        internal void Write()
        {
            int sfNumber = 0;
            using (StreamWriter file = new StreamWriter(OutputFilePath))
            {
                string outputHeader = string.Format("SmartFailureNumber\tDeviceModel\tSerialNumber\tLU_WWN_Device\tFirmwareVersion\tUserCapacity\tSectorSizes\tDeviceIs\tATAVersionIs\tATAStandardIs\tLocalTimeIs\tSmartSupportAvailable\tSmartSupportEnabled\tAttr_IdNumber\tAttr_Name\tAttr_Flag\tAttr_Value\tAttr_Worst\tAttr_Thresh\tAttr_Type\tAttr_Updated\tAttr_WhenFailed\tAttr_RawValue");
                file.WriteLine(outputHeader);

                foreach (SmartFailures sf in SmartFailuresList)
                {
                    if (sf.DeviceModel.StartsWith("ST"))
                    {
                        sfNumber++;
                        foreach (SmartFailuresProperty sp in sf.SmartFailuresProperties)
                        {
                            string output = string.Format("{0}\t{1}\t{2}\t{3}\t{4}\t{5}\t{6}\t{7}\t{8}\t{9}\t{10}\t{11}\t{12}\t{13}\t{14}\t{15}\t{16}\t{17}\t{18}\t{19}\t{20}\t{21}\t{22}",
                            sfNumber,
                            sf.DeviceModel,
                            sf.SerialNumber,
                            sf.LU_WWN_Device,
                            sf.FirmwareVersion,
                            sf.UserCapacity,
                            sf.SectorSizes,
                            sf.DeviceIs,
                            sf.ATAVersionIs,
                            sf.ATAStandardIs,
                            sf.LocalTimeIs,
                            sf.SmartSupportAvailable,
                            sf.SmartSupportEnabled,
                            sp.IdNumber,
                            sp.AttributeName,
                            sp.Flag,
                            sp.Value,
                            sp.Worst,
                            sp.Thresh,
                            sp.Type,
                            sp.Updated,
                            sp.WhenFailed,
                            sp.RawValue);

                            file.WriteLine(output);
                        }
                    }
                }
            }
        }
        #endregion
    }
}