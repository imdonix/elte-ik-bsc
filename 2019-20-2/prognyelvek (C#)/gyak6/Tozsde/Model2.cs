namespace WindowsFormsApp36
{
    using System;
    using System.Data.Entity;
    using System.ComponentModel.DataAnnotations.Schema;
    using System.Linq;

    public partial class Model2 : DbContext
    {
        public Model2()
            : base("name=Model2")
        {
        }

        public virtual DbSet<adasvetel> AdasVetelek { get; set; }

        protected override void OnModelCreating(DbModelBuilder modelBuilder)
        {
            modelBuilder.Entity<adasvetel>()
                .Property(e => e.vasarlas_Id)
                .HasPrecision(4, 0);

            modelBuilder.Entity<adasvetel>()
                .Property(e => e.termekneve)
                .IsUnicode(false);

            modelBuilder.Entity<adasvetel>()
                .Property(e => e.ar)
                .HasPrecision(10, 2);
        }
    }
}
