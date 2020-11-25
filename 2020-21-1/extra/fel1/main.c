#include <stdio.h>

struct Tire
{
    float time;
    int wear_start;
    float wear_amount;
    int tear_start;
    float tear_amount;
};


int main()
{
    FILE* in = fopen("be.txt", "rb");
	FILE* out = fopen("ki.txt", "wb+");

    struct Tire tires[3]; 
    int laps;
    float box;
    
    for(int i = 0; i < 3; i++)
    {
        int index = ((char)fgetc(in)) -  'A';
        if(!fscanf(in, "%f %i %f %i %f\n", &tires[index].time, &tires[index].wear_start, &tires[index].wear_amount, &tires[index].tear_start, &tires[index].tear_amount))
        {
            fputs("HIBA\n", out);
            return 1;
        }
    }
    fscanf(in, "%i\n%f\n", &laps, &box);

    float time = .0f;
    int lap = 1;
    int progress;

    int nextpit;
    char next;
    char old;

    fscanf(in, "%i%c", &nextpit, &next);
    old = next -'A';
    while(getc(in) != EOF)
    {
        fscanf(in, "%i%c", &nextpit, &next);
        float toadd = tires[old].time;
        for (progress = 0; lap <= nextpit; progress++, lap++)
        {
            int wear = (progress+1) - tires[old].wear_start;
            if(wear > 0) toadd += tires[old].wear_amount;

            int tear = (progress+1) - (tires[old].tear_start + tires[old].wear_start);
            if(tear > 0) toadd += tear * tires[old].tear_amount;

            time += toadd;   
        }

        old = next - 'A';
        time += box;
    }

    time -= box;

    float toadd = tires[old].time;
    for(progress = 0; lap <= laps; progress++, lap++)
    {
        int wear = (progress+1) - tires[old].wear_start;
        if(wear > 0) toadd += tires[old].wear_amount;

        int tear = (progress+1) - (tires[old].tear_start + tires[old].wear_start);
        if(tear > 0) toadd += tear * tires[old].tear_amount;

        time += toadd;   
    }

    fprintf(out, "%.3f\n", time);
}