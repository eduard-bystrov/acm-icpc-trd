struct Treap
{
	int _size;
	static int sizeOf(const Treap *t)
	{
		return t ? t->_size : 0;
	}

	Treap *l, *r;
	int y;

	Treap() : l(0), r(0), y((rand() << 0xf) ^ rand()), _size(1)
	{ }
	Treap(Treap *base, Treap *l, Treap *r) : l(l), r(r), y(base->y), _size(1)
	{
		_size += sizeOf(l) + sizeOf(r);
		delete base;
	}	

	static Treap* Merge(Treap *l, Treap *r)
	{
		if (!l) return r;
		if (!r) return l;
		if (l->y > r->y)
		{
			return new Treap(l, l->l, Merge(l->r, r));
		}
		else
		{		
			return new Treap(r, Merge(l, r->l), r->r);
		}
	}

	void Split(Treap *&l, Treap *&r, int count)
	{
		Treap *nt;
		l = r = nt = 0;
		int leftCount = sizeOf(this->l);
		if (count <= leftCount)
		{
			if (this->l) this->l->Split(l, nt, count);
			r = new Treap(this, nt, this->r);
		}
		else
		{		
			if (this->r) this->r->Split(nt, r, count - leftCount - 1);
			l = new Treap(this, this->l, nt);
		}
	}
	
	Treap* Insert(Treap *nt, int index)
	{
		Treap *l, *r;
		Split(l, r, index);
		return Merge(Merge(l, nt), r);
	}
	
	Treap* Remove(int index, Treap *&removed)
	{
		Treap *l, *r;
		Split(l, r, index);
		r->Split(removed, r, 1);
		return Merge(l, r);
	}
	
	Treap* Remove(int index)
	{
		Treap *l, *r, *m;
		Split(l, r, index);
		r->Split(m, r, 1);
		delete m;
		return Merge(l, r);
	}

	void ToVector(vint &v)
	{
		if (l) l->ToVector(v);
		v.push_back(y);
		if (r) r->ToVector(v);
	}

	static Treap* FromVector(const vint &v)
	{
		if (v.empty()) return 0;
		Treap *t = new Treap(/*v[0]*/);
		for(int i = 1; i < v.size(); i++)
		{
			t = Merge(t, new Treap(/*v[i]*/));
		}
		return t;
	}
};