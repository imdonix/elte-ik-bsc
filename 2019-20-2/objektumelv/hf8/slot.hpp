class Slot
{
    private:
        int _display;
    public:
        Slot() : _display(0) {};
        int get_display() { return _display;}
        void clear() {_display = 0;}
        void fill(int amount) { _display+=amount; }
};