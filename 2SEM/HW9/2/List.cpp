#include "List.h"

List::List() :
    head(NULL),
    tail (NULL),
    size(0)
{

}

List::~List()
{
    if (size > 0)
        delete head;
}

bool List::isEmpty()
{
    return size == 0;
}

void List::add(string str, unsigned int quantity)
{
    if (size == 0)
    {
        ListElement *temp = new ListElement(str);
        head = temp;
        tail = temp;
        head->setElemCounter(temp->getElemCounter() + quantity);
        size++;
    }
    else
    {
        ListElement *tmp = head;
        while (tmp->getNext() != NULL)
        {
            if (tmp->getStr() == str)
            {
                tmp->setElemCounter(tmp->getElemCounter() + quantity);
                return;
            }
            tmp = tmp->getNext();
        }
        if (tail->getStr() == str)
        {
            tmp->setElemCounter(tmp->getElemCounter() + quantity);
            return;
        }
        else
        {
            ListElement *temp = new ListElement(str, tail, NULL);
            temp->setElemCounter(temp->getElemCounter() + quantity);
            tail->setNext(temp);
            tail = temp;
            size++;
        }
    }
}

void List::remove(string str) throw (string)
{
    if (size >= 2)
    {
        if (head->getStr() == str)
        {
            ListElement *toDel = head;
            head = head->getNext();
            head->setPrev(NULL);
            toDel->setNext(NULL);
            delete toDel;
            size--;
            return;
        }
        ListElement *temp = head->getNext();
        while(temp->getNext() != NULL)
        {
            if (temp->getStr() == str)
            {
                temp->getNext()->setPrev(temp->getPrev());
                temp->getPrev()->setNext(temp->getNext());
                delete temp;
                size--;
                return;
            }
            temp = temp->getNext();
        }
        if (tail->getStr() == str)
        {
            ListElement *toDel = tail;
            tail = tail->getPrev();
            tail->setNext(NULL);
            size--;
            delete toDel;
            return;
        }
        throw string("No such word!");
    }
    else if (size == 1)
    {
        if (head->getStr() == str)
        {
            delete head;
            size--;
            return;
        }
        throw string("No such word!");
    }
    else
        throw string("List is Empty!");
}

bool List::exists(string str)
{
    ListElement *temp = head;
    while (temp->getNext() != NULL)
    {
        if (str == temp->getStr())
        {
            return true;
        }
        else
            temp = temp->getNext();
    }
    return temp->getStr() == str;
}
