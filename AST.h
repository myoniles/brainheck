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

class AstListNode : public AstNode {
	public:
		AstListNode( );
		AstListNode( AstNode* exp, AstListNode* next);
		void traverse();
};

class AstPrintNode : public AstNode {
	public:
		void traverse();
};

class AstReadNode : public AstNode {
	public:
		void traverse();
};

class AstExpressionNode : public AstNode {
	public:
		AstExpressionNode( );
		AstExpressionNode( int val );
		virtual void traverse();

		AstExpressionNode& operator+ (AstExpressionNode const &node);

	protected:
		int val;
};

class AstValueNode : public AstExpressionNode {
	public:
		AstValueNode( );
		AstValueNode( int val );
		void traverse();
};

class AstPositionNode : public AstExpressionNode {
	public:
		AstPositionNode( );
		AstPositionNode( int val );
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
