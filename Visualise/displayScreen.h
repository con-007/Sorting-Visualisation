#ifndef DISPLAYSCREEN_H
#define DISPLAYSCREEN_H


extern int swapflag;
extern int i,j;
extern int flag;
extern int dirflag;
extern int count;
extern int sorting;


class displayScreen
{
    public:
        displayScreen();
        virtual ~displayScreen();
        void bitmap_output(int x, int y, char *string, void *font);
        void display_text();

    protected:

    private:
};

#endif // DISPLAYSCREEN_H
