namespace Tickets
{
    using System;
    using System.Data.Entity;
    using System.ComponentModel.DataAnnotations.Schema;
    using System.Linq;

    public partial class TickModel : DbContext
    {
        public TickModel()
            : base("name=TickModel")
        {
        }

        public virtual DbSet<Bejelento> Bejelento { get; set; }
        public virtual DbSet<BekuldottTicketek> BekuldottTicketek { get; set; }

        protected override void OnModelCreating(DbModelBuilder modelBuilder)
        {
            modelBuilder.Entity<Bejelento>()
                .Property(e => e.Id)
                .HasPrecision(2, 0);

            modelBuilder.Entity<Bejelento>()
                .Property(e => e.Nev)
                .IsUnicode(false);

            modelBuilder.Entity<Bejelento>()
                .Property(e => e.Beosztas)
                .IsUnicode(false);

            modelBuilder.Entity<Bejelento>()
                .Property(e => e.Email)
                .IsUnicode(false);

            modelBuilder.Entity<Bejelento>()
                .HasMany(e => e.BekuldottTicketek)
                .WithRequired(e => e.Bejelento)
                .WillCascadeOnDelete(false);

            modelBuilder.Entity<BekuldottTicketek>()
                .Property(e => e.Id)
                .HasPrecision(2, 0);

            modelBuilder.Entity<BekuldottTicketek>()
                .Property(e => e.BejelentoId)
                .HasPrecision(2, 0);

            modelBuilder.Entity<BekuldottTicketek>()
                .Property(e => e.Uzenet)
                .IsUnicode(false);
        }
    }
}
