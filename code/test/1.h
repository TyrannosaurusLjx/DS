#ifdef TREE
#define TREE


template <typename Comparable>

class BinaryTree
{
  public:
    BinaryTree( ): root {nullptr}{}

    ~BinaryTree( )
    {
      makeEmpty();
    }

    void makeEmpty()
    {
      makeEmpty( root );
    }


  private:
    struct BinaryNode
    {
      Comparable element;
      

    };

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
    

}




















#endif 