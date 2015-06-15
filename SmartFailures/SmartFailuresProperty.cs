using System;
using System.Collections.Generic;
using System.Text;

namespace SmartFailures
{
    public class SmartFailuresProperty
    {
        internal string IdNumber { get; set; }

        internal string AttributeName { get; set; }

        internal string Flag { get; set; }

        internal string Value { get; set; }

        internal string Worst { get; set; }

        internal string Thresh { get; set; }

        internal string Type { get; set; }

        internal string Updated { get; set; }

        internal string WhenFailed { get; set; }

        internal string RawValue { get; set; }
    }
}