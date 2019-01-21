#ifndef TEMPLATES_H_
#define TEMPLATES_H_

#include <stdio.h>

#define CAT(X,Y) X##_##Y
#define TEMPLATE(X,Y) CAT(X,Y)
#define mkstr(s) #s 


#define define_list(type) \
\
    struct _list_##type; \
    \
    typedef struct \
    { \
        bool (*is_empty)(const struct _list_##type*); \
        size_t (*size)(const struct _list_##type*); \
        const type (*front)(const struct _list_##type*); \
        void (*push_front)(struct _list_##type*, type); \
        void (*display)(const struct _list_##type*); \
    } _list_functions_##type; \
    \
    typedef struct _list_elem_##type \
    { \
        type _data; \
        struct _list_elem_##type* _next; \
    } list_elem_##type; \
    \
    typedef struct _list_##type \
    { \
        size_t _size; \
        list_elem_##type* _first; \
        list_elem_##type* _last; \
        _list_functions_##type* _functions; \
    } List_##type; \
    \
    List_##type* new_list_##type(); \
    bool list_is_empty_##type(const List_##type* list); \
    size_t list_size_##type(const List_##type* list); \
    const type list_front_##type(const List_##type* list); \
    void list_push_front_##type(List_##type* list, type elem); \
    void list_display_##type(const List_##type* list); \
    \
    bool list_is_empty_##type(const List_##type* list) \
    { \
        return list->_size == 0; \
    } \
    \
    size_t list_size_##type(const List_##type* list) \
    { \
        return list->_size; \
    } \
    \
    const type list_front_##type(const List_##type* list) \
    { \
        return list->_first->_data; \
    } \
    \
    void list_push_front_##type(List_##type* list, type elem) \
    { \
        list_elem_##type* node = (list_elem_##type*)malloc(sizeof(list_elem_##type)); \
        node->_data = elem; \
        node->_next = list->_first; \
        list->_first = node; \
        list->_size++; \
    } \
    void list_display_##type(const List_##type* list) \
    { \
        list_elem_##type* elem = list->_first; \
        while(elem != NULL) \
        { \
             \
            elem++; \
        } \
    } \
    \
    _list_functions_##type _list_funcs_##type = { \
        &list_is_empty_##type, \
        &list_size_##type, \
        &list_front_##type, \
        &list_push_front_##type, \
        &list_display_##type, \
    }; \
    \
    List_##type* new_list_##type() \
    { \
        List_##type* res = (List_##type*) malloc(sizeof(List_##type)); \
        res->_size = 0; \
        res->_first = NULL; \
        res->_last = NULL;\
        res->_functions = &_list_funcs_##type; \
        return res; \
    }

#define List(type) \
    List_##type

#define new_list(type) \
    new_list_##type()

#define is_empty(collection) \
    collection->_functions->is_empty(collection)

#define size(collection) \
    collection->_functions->size(collection)

#define front(collection) \
    collection->_functions->front(collection)

#define push_front(collection, elem) \
    collection->_functions->push_front(collection, elem)

#define display_element(collection) \
    collection->_functions->display(collection)

#endif