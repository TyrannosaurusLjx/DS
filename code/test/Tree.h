#ifndef TREE
#define TREE

#include <iostream>

class BinaryNode; 
template <typename Comparable>

class BinaryTree
{
  public:
    BinaryTree() : root{nullptr;} {}


    ~BinaryTree(){
      makeEmpty();
    }

  // makeEmpty
  void makeEmpty()
  {
    makeEmpty( root );
  }

  // printTree
  void printTree()
  {
    printTree( root );
  }

  void err( std::string s ){
    std::cout<<"something get wrong, "<< s << std::endl;
  }

  private:
  // def BinaryNode here
    struct BinaryNode
    {
      Comparable element;
      BinaryNode *left;
      BinaryNode *right;
      
      // 左值引用
      BinaryNode (const Comparable & theelement, BinaryNode *lt, BinaryNode *rt)
        {
           element ( theelement ); left ( lt ); right ( rt ) ;
        }
      // 右值引用
      BinaryNode (Comparable && theelement, BinaryNode *lt, BinaryNode *rt)
        : element ( std::move( theelement ) ), left ( lt ), right ( rt ) {}
    };

  // get root BinaryNode

  BinaryNode *root;

  // make empty
  void makeEmpty( BinaryNode * & t )
  {
    if( t != nullptr)
    {
      makeEmpty( t->left );
      makeEmpty( t->right );
      delete t;
    }
    t = nullptr;
  }

  void printTree( BinaryNode *t) const
  {
      if( t != nullptr )
      {
          printTree( t->left );
          std::cout << t->element << std::endl;
          printTree( t->right );
      }
  }


}; 





























#endif //TREE