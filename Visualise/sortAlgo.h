#ifndef SORTALGO_H
#define SORTALGO_H
#define MAX 80

extern int a[MAX];
extern int swapflag;
extern int i,j;
extern int flag;
extern int dirflag;
extern int count;
extern int sorting;

class sortAlgo
{
    public:
        sortAlgo();
        virtual ~sortAlgo();
        int notsorted();
        void insertionsort();
        void selectionsort();
        void bubblesort();
        void ripplesort();

    protected:

    private:
};

#endif // SORTALGO_H
