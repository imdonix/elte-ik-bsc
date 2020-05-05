namespace MintaZH
{
    using System;
    using System.Data.Entity;
    using System.ComponentModel.DataAnnotations.Schema;
    using System.Linq;

    public partial class AlatModel : DbContext
    {
        public AlatModel()
            : base("name=AlatModel")
        {
        }

        public virtual DbSet<Aru> Aru { get; set; }
        public virtual DbSet<Vasarlas> Vasarlas { get; set; }
        public virtual DbSet<Vevo> Vevo { get; set; }

        protected override void OnModelCreating(DbModelBuilder modelBuilder)
        {
            modelBuilder.Entity<Aru>()
                .Property(e => e.Megnevezes)
                .IsUnicode(false);

            modelBuilder.Entity<Aru>()
                .Property(e => e.Tipus)
                .IsUnicode(false);

            modelBuilder.Entity<Aru>()
                .HasMany(e => e.Vasarlas)
                .WithRequired(e => e.Aru)
                .HasForeignKey(e => e.TermekId)
                .WillCascadeOnDelete(false);

            modelBuilder.Entity<Vasarlas>()
                .Property(e => e.Datum)
                .IsUnicode(false);

            modelBuilder.Entity<Vevo>()
                .Property(e => e.Nev)
                .IsUnicode(false);

            modelBuilder.Entity<Vevo>()
                .Property(e => e.Cim)
                .IsUnicode(false);

            modelBuilder.Entity<Vevo>()
                .HasMany(e => e.Vasarlas)
                .WithRequired(e => e.Vevo)
                .HasForeignKey(e => e.UgyfelId)
                .WillCascadeOnDelete(false);
        }
    }
}
