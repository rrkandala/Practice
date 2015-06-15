using System;
using System.Configuration;

namespace Microsoft.Csi.Hqse.SmartFailures
{
    public class SmartFailuresTest
    {
        // Program execution starts here
        static void Main()
        {
            string inputFilePath = ConfigurationManager.AppSettings.Get("InputFilePath");
            string outputFilePath = ConfigurationManager.AppSettings.Get("OutputFilePath");

            SmartFailuresMain sm = new SmartFailuresMain(inputFilePath, outputFilePath);

            // Parse file
            sm.Parse();

            // Print results
            sm.Write();

            // Completion message
            Console.WriteLine("Parsing Complete");
            Console.WriteLine("Output at location: {0}", outputFilePath);
            Console.ReadLine();
        }
    }
}
