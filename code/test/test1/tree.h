# include <iostream>
# include"../../dsexceptions.h"
#include<algorithm>

/// BinaryTree

template <typename Comparable>
class BinaryTree
{
  public:

    BinaryTree(){root = nullptr;}

    /**
     * Destructor for the tree
     */
    ~BinaryTree( )
    {
        makeEmpty( );
    }

    /**
     * Test if the tree is logically empty.
     * Return true if empty, false otherwise.
     */
    bool isEmpty() const
    {
        return root == nullptr;
    }

    /**
     * Print the tree contents in sorted order.
     */
    void printTree() const
    {
        // std::cout<<"调用了binarytree外部的printtree"<<std::endl;
        if( isEmpty() ){
            std::cout<<"Empty tree"<<std::endl;
        }
        else{
            printTree(root);
        }
    }

    /**
     * Make the tree logically empty.
     */
    void makeEmpty( )
    {
        // std::cout<<"调用了binarytree外部的makeempty"<<std::endl;
        makeEmpty( root );
    }





  protected:
    struct BinaryNode
    {
        Comparable element;
        BinaryNode * left;
        BinaryNode * right;

        BinaryNode(const Comparable & theElement, BinaryNode * lt, BinaryNode * rt)
        : element(theElement), left(lt), right(rt) {} 

        BinaryNode(const Comparable && theElement, BinaryNode * lt, BinaryNode * rt)
        : element(std::move(theElement)), left(lt), right(rt) {} 
    };

    BinaryNode *root;

    /**
     * Internal method to print a subtree rooted at t in sorted order.
     */
    void printTree(BinaryNode *t) const
    {
        // std::cout<<"调用了binarytree内部的printtree"<<std::endl;
        if(t != nullptr){
            printTree(t->left);
            std::cout<<t->element<<std::endl;
            printTree(t->right);
        }
    }

    /**
     * Internal method to make subtree empty.
     */
    void makeEmpty( BinaryNode * & t )
    {
        // std::cout<<"调用了binarytree内部的makeempty"<<std::endl;
        if( t != nullptr )
        {
            makeEmpty( t->left );
            makeEmpty( t->right );
            delete t;
        }
        t = nullptr;
    }
};












/// BinarySearchTree
template<typename Comparable>
class BinarySearchTree: public BinaryTree<Comparable>
{
  public:

    using BinaryTree<Comparable>::makeEmpty;
    using BinaryTree<Comparable>::isEmpty;
    using BinaryTree<Comparable>::printTree;

///
    /**
     * Internal method to print a subtree rooted at t in sorted order.
     */

    // void printTree() const
    // {   if(root == nullptr)
    // {
    //     std::cout<<"empty tree!"<<std::endl;
    // }
    //     printTree(root);
    // }





    BinarySearchTree( ) { root= nullptr;}
    
    /**
     * Copy constructor
     */
    BinarySearchTree( const BinarySearchTree & rhs )
    {
        root = clone( rhs.root );
    }

    /**
     * Move constructor
     */
    BinarySearchTree( BinarySearchTree && rhs ) 
    {
        root =  rhs.root ;
        rhs.root = nullptr;
    }
    
    /**
     * Destructor for the tree
     */
    ~BinarySearchTree( )
    {
        makeEmpty();
    }

    /**
     * Copy assignment
     */
    BinarySearchTree & operator=( const BinarySearchTree & rhs )
    {
        BinarySearchTree copy = rhs;
        std::swap( *this, copy );
        return *this;
    }
        
    /**
     * Move assignment
     */
    BinarySearchTree & operator=( BinarySearchTree && rhs )
    {
        std::swap( root, rhs.root );       
        return *this;
    }
    
    /**
     * Find the smallest item in the tree.
     * Throw UnderflowException if empty.
     */
    const Comparable & findMin( ) const
    {
        if( isEmpty( ) )
            throw UnderflowException{ };
        return findMin( root )->element;
    }

    /**
     * Find the largest item in the tree.
     * Throw UnderflowException if empty.
     */
    const Comparable & findMax( ) const
    {
        if( isEmpty( ) )
            throw UnderflowException{ };
        return findMax( root )->element;
    }

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
        std::cout<<"外部左值插入"<<std::endl;
        insert( x, root );
    }
     
    /**
     * Insert x into the tree; duplicates are ignored.
     */
    void insert( Comparable && x )
    {
        // std::cout<<"外部右值插入"<<std::endl;
        insert( std::move( x ), root );
    }
    
    /**
     * Remove x from the tree. Nothing is done if x is not found.
     */
    void remove( const Comparable & x )
    {
        remove( x, root );
    }



//   protected:

// class BinaryNode : public BinaryTree<Comparable>::BinaryNode  
// {  
// public:  
//     Comparable element;  
//     BinaryNode *left;  
//     BinaryNode *right;  
    
//     BinaryNode(const Comparable & theElement, BinaryNode *lt, BinaryNode *rt) : BinaryTree<Comparable>::BinaryNode(theElement, lt, rt), element(theElement), left(lt), right(rt) {}  
//     BinaryNode(const Comparable && theElement, BinaryNode * lt, BinaryNode * rt) : BinaryTree<Comparable>::BinaryNode(theElement, lt, rt), element(std::move(theElement)), left(lt), right(rt) {} 
// };
 
// BinaryNode *root;  



  protected:


    using typename BinaryTree<Comparable>::BinaryNode;

    BinaryNode *root;


    /**
     * Internal method to insert into a subtree.
     * x is the item to insert.
     * t is the node that roots the subtree.
     * Set the new root of the subtree.
     */
    void insert( const Comparable & x, BinaryNode * & t )
    {
        // std::cout<<"左值插入内部"<<std::endl;
        if( t == nullptr ){
            t = new BinaryNode{ x, nullptr, nullptr };
            std::cout<<"t.element = "<<t->element<<std::endl;}
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
        // std::cout<<"右值插入内部"<<std::endl;
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
    void remove( const Comparable & x, BinaryNode * & t )
    {
        if( t == nullptr )
            return;   // Item not found; do nothing
        if( x < t->element )
            remove( x, t->left );
        else if( t->element < x )
            remove( x, t->right );
        else if( t->left != nullptr && t->right != nullptr ) // Two children
        {
            t->element = findMin( t->right )->element;
            remove( t->element, t->right );
        }
        else
        {
            BinaryNode *oldNode = t;
            t = ( t->left != nullptr ) ? t->left : t->right;
            delete oldNode;
        }
    }

    /**
     * Internal method to find the smallest item in a subtree t.
     * Return node containing the smallest item.
     */
    BinaryNode * findMin( BinaryNode *t ) const
    {
        if( t == nullptr )
            return nullptr;
        if( t->left == nullptr )
            return t;
        return findMin( t->left );
    }

    /**
     * Internal method to find the largest item in a subtree t.
     * Return node containing the largest item.
     */
    BinaryNode * findMax( BinaryNode *t ) const
    {
        if( t != nullptr )
            while( t->right != nullptr )
                t = t->right;
        return t;
    }


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


    /**
     * Internal method to clone subtree.
     */
    BinaryNode * clone( BinaryNode *t ) const
    {
        if( t == nullptr )
            return nullptr;
        else
            return new BinaryNode{ t->element, clone( t->left ), clone( t->right ) };
    }





// ///
    // void printTree( BinaryNode *t) const
    // {
    //     // std::cout<<"自己的printTree"<<std::endl;
    //     if( t != nullptr )
    //     {
    //         printTree( t->left );
    //         std::cout << t->element << std::endl;
    //         printTree( t->right );
    //     }
    // }

};








