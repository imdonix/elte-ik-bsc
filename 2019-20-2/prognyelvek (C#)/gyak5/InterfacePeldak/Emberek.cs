using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace InterfacePeldak
{
   public class Emberek : IEnumerable
    {
        public Ember[] EmberekTomb { get; set; }

        public Emberek(Ember[] emberek)
        {
            EmberekTomb = emberek;
        }

        public IEnumerator GetEnumerator()
        {
            return new EmberekEnumerator(EmberekTomb);
        }
    }

    public class EmberekEnumerator : IEnumerator
    {
        public Ember[] Sokember2 { get; set; }

        int pos = -1;

        public EmberekEnumerator(Ember[] embek)
        {
            Sokember2 = embek;
        }

        public object Current => Sokember2[pos];

        public bool MoveNext()
        {
            pos++;
            if (pos >= Sokember2.Length)
            {
                return false;
            }
            return true;
        }

        public void Reset()
        {
            pos = -1;
        }
    }


}
