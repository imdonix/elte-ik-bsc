namespace Tickets
{
    using System;
    using System.Collections.Generic;
    using System.ComponentModel.DataAnnotations;
    using System.ComponentModel.DataAnnotations.Schema;
    using System.Data.Entity.Spatial;

    [Table("BekuldottTicketek")]
    public partial class BekuldottTicketek
    {

        public enum Status 
        {
            Archive,
            New,
            InProgress,
            Ended
        }

        [Column(TypeName = "numeric")]
        public decimal Id { get; set; }

        [Column(TypeName = "numeric")]
        public decimal BejelentoId { get; set; }

        public DateTime Datum { get; set; }

        public int Statusz { get; set; }

        [Required]
        [StringLength(200)]
        public string Uzenet { get; set; }

        public virtual Bejelento Bejelento { get; set; }

        public BekuldottTicketek(){}

        public BekuldottTicketek(decimal bejelentoId, DateTime datum, int statusz, string uzenet)
        {
            BejelentoId = bejelentoId;
            Datum = datum;
            Statusz = statusz;
            Uzenet = uzenet;
        }

        public override string ToString()
        {
            return Uzenet;
        }
    }
}
