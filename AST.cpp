#include "AST.h"
#include <cstddef>
#include <stdio.h>

#ifndef AST
#define AST

void yyerror(const char* s);
//char* ptr, mem;

char mem[30000] = {0};
char* ptr = mem;

void status_update(){
	printf("current ptr:\t%p,\tcurrent *ptr:\t%d\n", ptr, *ptr);
}

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

AstListNode::AstListNode()
:AstNode()
{
  this->leftChild =  NULL;
  this->rightChild = NULL;
}


AstListNode::AstListNode(AstNode* exp, AstListNode* next) :
AstNode(exp, next){
}

void AstListNode::traverse(){
	if ( rightChild )
		rightChild->traverse();
	leftChild ->traverse();
}

AstExpressionNode::AstExpressionNode()
:AstNode()
{
  this->leftChild =  NULL;
  this->rightChild = NULL;
}

AstExpressionNode::AstExpressionNode(AstOp op) :
AstNode(){
	this->op = op;
	this->val = 0;
}

AstExpressionNode::AstExpressionNode(AstOp op, int val) :
AstNode(){
	this->op = op;
	this->val = val;
}

void printbyte(char a){
	int i;
	for (i = 0; i < 8; i++) {
			printf("%d", !!((a << i) & 0x80));
	}
	printf(" ");
}

void AstExpressionNode::traverse(){
	switch (op){
		case val_delta:
			*ptr += val;
			break;
		case pos_delta:
			ptr += val;
			break;
		case print:
			//printbyte(*ptr);
			printf("%c", *ptr);
			break;
		case readc:
			*ptr = getchar();
			break;
	}
	//status_update();
}

AstLoopNode::AstLoopNode(AstListNode* inside):AstNode(){this->inside = inside;}

void AstLoopNode::traverse(){
	if (inside==NULL)
		return;
	char* og_ptr = ptr;
	while(*ptr){
		inside->traverse();
	}
}

#endif
