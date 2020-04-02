namespace KajaldaKivalasztas
{
    using System;
    using System.Data.Entity;
    using System.ComponentModel.DataAnnotations.Schema;
    using System.Linq;

    public partial class KajaModel : DbContext
    {
        public KajaModel()
            : base("name=KajaModel")
        {
        }

        public virtual DbSet<Kajaldak> Kajaldak { get; set; }

        protected override void OnModelCreating(DbModelBuilder modelBuilder)
        {
        }
    }
}
