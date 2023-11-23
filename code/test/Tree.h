#include <algorithm>

template <typename Comparable>
class BinaryTree
{
  public:
    BinaryTree( ): root {nullptr}{}

    /**
     * Copy constructor
     */
    BinaryTree( const BinaryTree & rhs ) : root{ nullptr }
    {
        root = clone( rhs.root );
    }


    /**
     * Move constructor
     */
    BinaryTree( BinaryTree && rhs ) : root{ rhs.root }
    {
        rhs.root = nullptr;
    }

    /**
     * Copy assignment
     */
    BinaryTree & operator=( const BinaryTree & rhs )
    {
        BinaryTree copy = rhs;
        std::swap( *this, copy );
        return *this;
    }
        
    

    ~BinaryTree( )
    {
      makeEmpty();
    }

    // makeempty
    void makeEmpty()
    {
      makeEmpty( root );
    }
    
    //printTree
    void printTree()
    {
      printTree( root , out);
    }

    // is empty?
    bool isEmpty()
    {
      return root == nullptr;
    }

  private:
    struct BinaryNode
    {
      Comparable element;
      BinaryNode * left;
      BinaryNode * right;

      BinaryNode( const Comparable & theelement, BinaryNode *& lt, BinaryNode *& rt)
      :element{ theelement }, left{ lt }, right{ rt }{}

      BinaryNode( Comparable && theelement, BinaryNode *& lt, BinaryNode *& rt)
      :element{ std::move(theelement) }, left{ lt }, right{ rt }{}
    
    };

    // tree root
    BinaryNode root;

    void makeEmpty( BinaryNode * & t )
    {
      if( t != nullptr )
      {
        makeEmpty( t->left );
        makeEmpty( t->right );
        delete t;
      }
      t = nullptr;
    }



    void printTree( BinaryNode *t, ostream & out ) const
    {
        if( t != nullptr )
        {
            printTree( t->left, out );
            out << t->element << endl;
            printTree( t->right, out );
        }
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


    

};




















