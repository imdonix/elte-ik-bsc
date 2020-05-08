namespace Tickets
{
    using System;
    using System.Collections.Generic;
    using System.ComponentModel.DataAnnotations;
    using System.ComponentModel.DataAnnotations.Schema;
    using System.Data.Entity.Spatial;

    [Table("Bejelento")]
    public partial class Bejelento
    {
        [System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Usage", "CA2214:DoNotCallOverridableMethodsInConstructors")]
        public Bejelento()
        {
            BekuldottTicketek = new HashSet<BekuldottTicketek>();
        }

        [Column(TypeName = "numeric")]
        public decimal Id { get; set; }

        [Required]
        [StringLength(255)]
        public string Nev { get; set; }

        [Required]
        [StringLength(200)]
        public string Beosztas { get; set; }

        [Required]
        [StringLength(40)]
        public string Email { get; set; }

        [System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Usage", "CA2227:CollectionPropertiesShouldBeReadOnly")]
        public virtual ICollection<BekuldottTicketek> BekuldottTicketek { get; set; }

        public override string ToString()
        {
            return Nev;
        }
    }
}
