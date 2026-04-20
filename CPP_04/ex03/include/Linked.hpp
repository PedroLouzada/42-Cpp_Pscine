
#ifndef LINKED_HPP
# define LINKED_HPP

# include "AMateria.hpp"

typedef struct s_linked
{
    private:
        static int _index;
        AMateria*  _trash;
        s_linked*  _head;
        s_linked*  _next;

    public:
        void        pushBack(AMateria* m);
        AMateria*   getTrash();
        static int  getIndex();
} t_linked;

#endif