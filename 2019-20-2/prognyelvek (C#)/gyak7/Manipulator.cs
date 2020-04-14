using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace KepSzintelenito
{
    static class Manipulator
    {
        public static Bitmap Manipulate(Bitmap bmp, int R, int G, int B)
        {
            for (int x = 0; x < bmp.Width; x++)
            {
                for (int y = 0; y < bmp.Height; y++)
                {
                    Color pixel = bmp.GetPixel(x, y);
                    bmp.SetPixel(x, y, Color.FromArgb((pixel.R + pixel.G + pixel.B) / 3, pixel.G, pixel.B));

                    //if (pixel.R > R || pixel.G > G || pixel.B > B)
                    //{
                    //    int colorValue = (pixel.R + pixel.G + pixel.B) / 3;
                    //    bmp.SetPixel(x, y, Color.FromArgb(colorValue, colorValue, colorValue));
                    //}
                }
            }
            return bmp;
        }
    }
}
