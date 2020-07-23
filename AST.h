#ifndef AST_H
#define AST_H

class AstNode{
	public:
		int lineno;

		AstNode();
		AstNode( AstNode* leftNode, AstNode* rightNode);

		virtual void traverse() = 0;
		void setLeftChild( AstNode* node );
		void setRightChild( AstNode* node );
		void setLineno(int i);

	protected:
		AstNode* leftChild;
		AstNode* rightChild;
};

enum AstOp {
	val_delta,
	pos_delta,
	print,
	readc
};

class AstExpressionNode : public AstNode {
	public:
		AstExpressionNode( );
		AstExpressionNode( AstOp op );
		AstExpressionNode( AstOp op , int val );
		void traverse();

	protected:
		AstOp op;
		int val;
};

class AstListNode : public AstNode {
	public:
		AstListNode( );
		AstListNode( AstNode* exp, AstListNode* next);
		void traverse();
};

class AstLoopNode: public AstNode {
	public:
		AstLoopNode( AstListNode* inside );
		void traverse();
	private:
		AstListNode* inside;
};

#endif
