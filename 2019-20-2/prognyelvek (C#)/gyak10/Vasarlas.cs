namespace MintaZH
{
    using System;
    using System.Collections.Generic;
    using System.ComponentModel.DataAnnotations;
    using System.ComponentModel.DataAnnotations.Schema;
    using System.Data.Entity.Spatial;

    public partial class Vasarlas
    {
        [DatabaseGenerated(DatabaseGeneratedOption.None)]
        public int Id { get; set; }

        public int UgyfelId { get; set; }

        public int TermekId { get; set; }

        public int Mennyiseg { get; set; }

        [Required]
        [StringLength(20)]
        public string Datum { get; set; }

        public virtual Aru Aru { get; set; }

        public virtual Vevo Vevo { get; set; }
    }
}
