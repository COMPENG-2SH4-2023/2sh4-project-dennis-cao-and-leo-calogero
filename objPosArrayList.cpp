#include "objPosArrayList.h"
#define DEFAULT_SIZE 200
// Check lecture contents on general purpose array list construction, 
// and modify it to support objPos array list construction.

objPosArrayList::objPosArrayList()
{
    aList= new objPos[DEFAULT_SIZE]; //array list of size default size, allocated on heap memory
    sizeList=0; //intial # of elements in list are zero
    sizeArray=DEFAULT_SIZE; //max capacity
}

objPosArrayList::~objPosArrayList()
{
    delete [] aList;  // free heap member 1D array
}

int objPosArrayList::getSize()
{
    return sizeList;  // returns size of List
}

void objPosArrayList::insertHead(objPos thisPos)
{
    if(sizeList==sizeArray)
    {
        return;   //exit function, no space for additional element
    }
    for(int i =sizeList ; i >0 ; i--) //move each element to the next index, creates duplicate value at index 0 and 1 
    {
        aList[i]=aList[i-1];
    }
    aList[0]=thisPos; //duplicate val is overwritten as new head element
    sizeList++; //increment size to reflect new element insertion
}

void objPosArrayList::insertTail(objPos thisPos)
{
    if(sizeList==sizeArray)
    {
        return;  //no room for additional element 
    }
    //size of list points where Tail element needs to be inserted
    aList[sizeList]=thisPos;
    sizeList++; //increment size to reflect new element insertion
}

void objPosArrayList::removeHead()
{
    if (sizeList==0)
    {
        //if list is empty there is nothing to remove
        return;
    }

    for(int i = 0 ; i <sizeList-1 ; i++)
    {
        aList[i]= aList[i+1]; //each element becomes previous up, thus overwriting the head
    }
    sizeList--; //deincrement size to reflect element removal
}

void objPosArrayList::removeTail()
{
    if (sizeList==0)
    {
        return;
    }
    
    sizeList--; //deincrementing size effectly makes last element "removed" by excluding it from list
}

void objPosArrayList::getHeadElement(objPos &returnPos)
{
    returnPos=aList[0]; // returns first element in list
}

void objPosArrayList::getTailElement(objPos &returnPos)
{
    returnPos=aList[sizeList-1]; // returns last element in list [size -1] 
}

void objPosArrayList::getElement(objPos &returnPos, int index)
{
    if(index>-1 && index<sizeList)
    {
        returnPos=aList[index]; // utilizes copy constructor in obj pos to succesfully copy obj pos at index into pos
    }
    
}