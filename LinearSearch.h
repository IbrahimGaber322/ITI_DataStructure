#ifndef LINEAR_SEARCH_H
#define LINEAR_SEARCH_H
#include "Employee.h"

class LinearSearch
{
private:
    /* data */
public:
    LinearSearch(/* args */){};
    ~LinearSearch(){};
    virtual int linearSearch() = 0;
};

class LinearSearchId : public LinearSearch
{
private:
    /* data */
public:
    LinearSearchId(/* args */){};
    ~LinearSearchId(){};
    int linearSearch(Employee arr[], int n, int target)
    {
        for (int i = 0; i < n; i++)
        {
            if (arr[i].getId() == target)
            {
                // Return the index if the target is found
                return i;
            }
        }

        // Return -1 if the target is not found
        return -1;
    };
};

class LinearSearchName : public LinearSearch
{
private:
    /* data */
public:
    LinearSearchName(/* args */){};
    ~LinearSearchName(){};
    int linearSearch(Employee arr[], int n, string target)
    {
        for (int i = 0; i < n; i++)
        {
            if (arr[i].getName() == target)
            {
                // Return the index if the target is found
                return i;
            }
        }

        // Return -1 if the target is not found
        return -1;
    };
};


#endif // LINEAR_SEARCH_H
