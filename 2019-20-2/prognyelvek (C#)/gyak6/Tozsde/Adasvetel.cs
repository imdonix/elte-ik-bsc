namespace WindowsFormsApp36
{
    using System;
    using System.Collections.Generic;
    using System.ComponentModel.DataAnnotations;
    using System.ComponentModel.DataAnnotations.Schema;
    using System.Data.Entity.Spatial;

    [Table("adasvetel")]
    public partial class adasvetel
    {
        [Key]
        [Column(TypeName = "numeric")]
        public decimal vasarlas_Id { get; set; }

        [Required]
        [StringLength(40)]
        public string termekneve { get; set; }

        public bool vetel { get; set; }

        public decimal ar { get; set; }

        public int darabszam { get; set; }

        public DateTime idopont { get; set; }
    }
}
