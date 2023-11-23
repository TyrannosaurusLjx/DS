#include "BT.h"

template <typename Comparable>
class BinarySearchTree: public BinaryTree<Comparable>
{
  public:




    /**
     * Find the smallest item in the tree.
     * Throw UnderflowException if empty.
     */
    // const Comparable & findMin( ) const
    // {
    //     if( isEmpty( ) )
    //         throw UnderflowException{ };
    //     return findMin( root )->element;
    // }

    /**
     * Find the largest item in the tree.
     * Throw UnderflowException if empty.
     */
    // const Comparable & findMax( ) const
    // {
    //     if( isEmpty( ) )
    //         throw UnderflowException{ };
    //     return findMax( root )->element;
    // }

    /**
     * Returns true if x is found in the tree.
     */
    bool contains( const Comparable & x ) const
    {
        return contains( x, root );
    }

    /**
     * Insert x into the tree; duplicates are ignored.
     */
    void insert( const Comparable & x )
    {
        insert( x, root );
    }

     
    /**
     * Insert x into the tree; duplicates are ignored.
     */
    // void insert( Comparable && x )
    // {
    //     insert( std::move( x ), root );
    // }

    /**
     * Remove x from the tree. Nothing is done if x is not found.
     */
    // void remove( const Comparable & x )
    // {
    //     remove( x, root );
    // }


  private:
    


    /**
     * Internal method to insert into a subtree.
     * x is the item to insert.
     * t is the node that roots the subtree.
     * Set the new root of the subtree.
     */
    void insert( const Comparable & x, BinaryNode * & t )
    {
        if( t == nullptr )
            t = new BinaryNode{ x, nullptr, nullptr };
        else if( x < t->element )
            insert( x, t->left );
        else if( t->element < x )
            insert( x, t->right );
        else
            ;  // Duplicate; do nothing
    }
    
    /**
     * Internal method to insert into a subtree.
     * x is the item to insert.
     * t is the node that roots the subtree.
     * Set the new root of the subtree.
     */
    void insert( Comparable && x, BinaryNode * & t )
    {
        if( t == nullptr )
            t = new BinaryNode{ std::move( x ), nullptr, nullptr };
        else if( x < t->element )
            insert( std::move( x ), t->left );
        else if( t->element < x )
            insert( std::move( x ), t->right );
        else
            ;  // Duplicate; do nothing
    }

    /**
     * Internal method to remove from a subtree.
     * x is the item to remove.
     * t is the node that roots the subtree.
     * Set the new root of the subtree.
     */
    // void remove( const Comparable & x, BinaryNode * & t )
    // {
    //     if( t == nullptr )
    //         return;   // Item not found; do nothing
    //     if( x < t->element )
    //         remove( x, t->left );
    //     else if( t->element < x )
    //         remove( x, t->right );
    //     else if( t->left != nullptr && t->right != nullptr ) // Two children
    //     {
    //         t->element = findMin( t->right )->element;
    //         remove( t->element, t->right );
    //     }
    //     else
    //     {
    //         BinaryNode *oldNode = t;
    //         t = ( t->left != nullptr ) ? t->left : t->right;
    //         delete oldNode;
    //     }
    // }

    /**
     * Internal method to find the smallest item in a subtree t.
     * Return node containing the smallest item.
     */
    // BinaryNode * findMin( BinaryNode *t ) const
    // {
    //     if( t == nullptr )
    //         return nullptr;
    //     if( t->left == nullptr )
    //         return t;
    //     return findMin( t->left );
    // }

    /**
     * Internal method to find the largest item in a subtree t.
     * Return node containing the largest item.
     */
    // BinaryNode * findMax( BinaryNode *t ) const
    // {
    //     if( t != nullptr )
    //         while( t->right != nullptr )
    //             t = t->right;
    //     return t;
    // }

    /**
     * Internal method to test if an item is in a subtree.
     * x is item to search for.
     * t is the node that roots the subtree.
     */
    bool contains( const Comparable & x, BinaryNode *t ) const
    {
        if( t == nullptr )
            return false;
        else if( x < t->element )
            return contains( x, t->left );
        else if( t->element < x )
            return contains( x, t->right );
        else
            return true;    // Match
    }










};





