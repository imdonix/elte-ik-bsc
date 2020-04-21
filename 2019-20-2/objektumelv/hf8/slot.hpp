class Slot
{
    private:
        int display;
    public:
        Slot(){};
        int get_display() { return display;};
        void fill(int amount){ display+=amount; }
};