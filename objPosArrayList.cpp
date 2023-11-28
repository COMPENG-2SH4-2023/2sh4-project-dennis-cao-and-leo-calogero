#include "objPosArrayList.h"
#define DEFAULT_SIZE 200
// Check lecture contents on general purpose array list construction, 
// and modify it to support objPos array list construction.

objPosArrayList::objPosArrayList()
{
    aList= new objPos[DEFAULT_SIZE];
    sizeList=0;
    sizeArray=DEFAULT_SIZE;
}

objPosArrayList::~objPosArrayList()
{
    delete [] aList;
}

int objPosArrayList::getSize()
{
    return sizeList;
}

void objPosArrayList::insertHead(objPos thisPos)
{
    if(sizeList==sizeArray)
    {
       // cout << "Array List is Full" << endl;
        return;
    }
    for(int i =sizeList ; i >0 ; i--)
    {
        aList[i]=aList[i-1];
    }
    aList[0]=thisPos;
    sizeList++;
}

void objPosArrayList::insertTail(objPos thisPos)
{
    if(sizeList==sizeArray)
    {
       // cout << "Array List is Full" << endl;
        return;
    }
    //size of list points where Tail element needs to be inserted
    aList[sizeList]=thisPos;
    sizeList++;
}

void objPosArrayList::removeHead()
{
    if (sizeList==0)
    {
        //cout << "list is empty, cannot remove" << endl;
        return;
    }

    for(int i = 0 ; i <sizeList-1 ; i++)
    {
        aList[i]= aList[i+1]; //each element becomes previous, thus overwriting the head
    }
    sizeList--;
}

void objPosArrayList::removeTail()
{
    if (sizeList==0)
    {
        // cout << "list is empty, cannot remove" << endl;
        return;
    }
    
    sizeList--;
}

void objPosArrayList::getHeadElement(objPos &returnPos)
{
    returnPos=aList[0];
}

void objPosArrayList::getTailElement(objPos &returnPos)
{
    returnPos=aList[sizeList-1];
}

void objPosArrayList::getElement(objPos &returnPos, int index)
{
    if(index>-1 && index<sizeList)
    {
        returnPos=aList[index];
    }
    
}