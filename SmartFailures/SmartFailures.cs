using System;
using System.Collections.Generic;
using System.Text;

namespace Microsoft.Csi.Hqse.SmartFailures
{
    public class SmartFailures
    {
        internal string DeviceModel { get; set; }

        internal string SerialNumber { get; set; }

        internal string LU_WWN_Device { get; set; }

        internal string FirmwareVersion { get; set; }

        internal string UserCapacity { get; set; }

        internal string SectorSizes { get; set; }

        internal string DeviceIs { get; set; }

        internal string ATAVersionIs { get; set; }

        internal string ATAStandardIs { get; set; }

        internal string LocalTimeIs { get; set; }

        internal string SmartSupportAvailable { get; set; }

        internal string SmartSupportEnabled { get; set; }

        internal List<SmartFailuresProperty> SmartFailuresProperties { get; set; }

        public SmartFailures()
        {
            SmartFailuresProperties = new List<SmartFailuresProperty>();
        }
    }
}