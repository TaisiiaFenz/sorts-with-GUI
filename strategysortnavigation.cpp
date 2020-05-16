#include "strategysortnavigation.h"



StrategySortNavigation::StrategySortNavigation(QObject *parent): QObject(parent)
{
    m_strategy=nullptr;
}


/*
 * @brief sort your array, based on what sort you have selected earlier
 * @details you need to randomizeVector and selectSort firstly
*/

void StrategySortNavigation::sort()
{
    if(!m_strategy){
        throw("m_strategy == nullptr .You need to select sort firstly");
    }
    else if(vectorToSort.empty()){
        throw("Your vector is empty.You need to create it firstly");
    }
    else{
        m_strategy->sort(vectorToSort);
    }
}

/*
  * @param howManyNumbers - size of array we want to create
  * @param from - begin of randomizing range
  * @param to - end of randomizing range
*/
void StrategySortNavigation::randomizeVector(int howManyNumbers, int from, int to){
    for( int i = 0; i < howManyNumbers;i++){
        vectorToSort.push_back(Randomizing::generateRandomInt(from,to));
    }
}

/*
  *brief creates m_strategy of needed sort, based on enums
*/
void StrategySortNavigation::selectSort(SortsEnums::SortChoice choosenSort){
    // TO DO
    // factory switch case based on enum
    // m_strategy = classCreatedByFactory
    switch (choosenSort) {
    case SortsEnums::SortChoice ::INSERTION_SORT : m_strategy = SortFactory::insertionSort();
        break;
    case SortsEnums::SortChoice ::QUICK_SORT : m_strategy = SortFactory::quickSort();
        break;
    case SortsEnums::SortChoice ::MERGE_RECURSIVE_SORT : m_strategy = SortFactory::recursiveMerge();
        break;
    case SortsEnums::SortChoice ::MERGE_ITERATIVE_SORT : m_strategy = SortFactory::iterationMerge();
        break;
    case SortsEnums::SortChoice ::MSD_RADIX : m_strategy = SortFactory::msdRadix();
        break;
    case SortsEnums::SortChoice ::LSD_RADIX : m_strategy = SortFactory::lsdRadix();
        break;
        // TO DO
    default:
        throw ("Wrong enum ");
        break;

    }

}
