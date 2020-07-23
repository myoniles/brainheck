#include "AST.h"

#ifndef AST
#define AST

void yyerror(const char* s);
char* ptr, mem;

AstNode::AstNode(AstNode* leftNode, AstNode* rightNode)
{
  this->leftChild = leftNode;
  this->rightChild = rightNode;
}

AstNode::AstNode()
{
  this->leftChild =  NULL;
  this->rightChild = NULL;
}

void AstNode::setLeftChild( AstNode* node )
{
  this->leftChild = node;
}

void AstNode::setLineno( int i )
{
  this->lineno = i;
}

void AstNode::setRightChild( AstNode* node )
{
  this->rightChild = node;
}

ASTListNode::ASTListNode(ASTExpressionNode* exp, ASTListNode* next) :
ASTNode(exp, next){

}

void ASTListNode::traverse(){
	leftChild ->traverse();
	if ( rightChild )
		rightChild->traverse()
}

ASTExpressionNode::ASTExpressionNode(AstOp op) :
ASTNode(){

}

void ASTExpressionNode::traverse(){
	switch (op){
		case val_delta:
			*ptr;
			break;
		case pos_delta:
			break;
		case print:
			printf("print: %c", *ptr);
			break;
		case read:
			*ptr = getchar();
			break;
		default:
	}
}

#endif
