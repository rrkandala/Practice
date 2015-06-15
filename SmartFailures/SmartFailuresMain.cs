using System;
using System.Collections.Generic;
using System.Collections.Specialized;
using System.Configuration;
using System.Text;

namespace Microsoft.Csi.Hqse.SmartFailures
{
    /// <summary>
    /// Main class containing the smart failures parsing logic
    /// </summary>
    public class SmartFailuresMain
    {
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

        /// <summary>
        /// Constructor initializing the input and output file paths from
        /// </summary>
        /// <param name="inputFilePath">Input file path containing smart hardware failures information</param>
        /// <param name="outputFilePath">Output file path written with parsed hardware failures</param>
        public SmartFailuresMain(string inputFilePath, string outputFilePath)
        {
            InputFilePath = inputFilePath;
            OutputFilePath = outputFilePath;
            SmartFailuresList = new List<SmartFailures>();
        }

        public void Parse()
        {

        }

        public void Write()
        {

        }
    }
}