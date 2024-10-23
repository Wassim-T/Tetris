/**
 * @file Observable.h
 * @brief Declares the Observable class interface.
 */

#ifndef TETRIS_OBSERVABLE_H
#define TETRIS_OBSERVABLE_H

#include "Observer.hpp"

namespace model {

/**
     * @class Observable
     * @brief Interface for observable objects.
     */
class Observable {
public:
    /**
         * @brief Adds an observer to the observable object.
         * @param observer Shared pointer to the observer to add.
         */
    virtual void addObserver(std::shared_ptr<Observer> observer) = 0;

    /**
         * @brief Removes an observer from the observable object.
         * @param observer Shared pointer to the observer to remove.
         */
    virtual void removeObserver(std::shared_ptr<Observer> observer) = 0;

    /**
         * @brief Notifies all observers with the given notification.
         * @param notification The notification to be sent to observers.
         */
    virtual void notifyObservers(Notification notification) = 0;
};
}

#endif //TETRIS_OBSERVABLE_H
