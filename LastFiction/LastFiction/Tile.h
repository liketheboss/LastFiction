#pragma once

class Tile
{
private:
	int _tid;

	bool _solid;
public:
	Tile(const int tid, bool solid);
	~Tile();

	int getTid() { return _tid; }
};

