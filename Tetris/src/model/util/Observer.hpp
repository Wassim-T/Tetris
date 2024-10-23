/**
 * @file Observer.hpp
 * @brief Declares the Observer interface.
 */

#ifndef TETRIS_OBSERVER_HPP
#define TETRIS_OBSERVER_HPP

#include "Notification.hpp"

namespace model {

/**
     * @class Observer
     * @brief Interface for observers.
     */
class Observer {
public:
    /**
         * @brief Updates the observer with a notification.
         * @param notification The notification to update the observer with.
         */
    virtual void update(Notification notification) = 0;
};

}

#endif //TETRIS_OBSERVER_HPP
