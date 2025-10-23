#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

const ld PI  = acosl(-1.0L);
const ld EPS = 1e-12L;

struct dot
{
	ld x, y;
	dot(ld _x = 0, ld _y = 0) {x = _x, y = _y;}
	dot operator -	(dot b) {return dot(x - b.x, y - b.y);}
	dot operator +	(dot b) {return dot(x + b.x, y + b.y);}
	dot operator *	(ld  b) {return dot(x * b, y * b);}
	ld  operator *	(dot b) {return x * b.x + y * b.y;}//内积
	dot operator /	(ld  b) {return dot(x / b, y / b);}
	ld  operator /	(dot b) {return x * b.y - y * b.x;}//外积
	ld  crs(dot b)	{return x * b.y - y * b.x;}
	ld  len()		{return sqrtl(x * x + y * y);}
	void input()	{scanf("%Lf %Lf", &x, &y);}
	void print(auto f) {fprintf(f, "The dot(vec) : (%.4Lf %.4Lf)\n", x, y);}
};

using vec2 = dot;

// 计算两直线交点在第一条线段上的位置距离：
// 交点 = p1 + v1 * t, 其中 t = (v2 x (p1 - p2)) / (v1 x v2)
// 返回 |v1| * t = 交点到 p1 的距离

ld ins(dot p1, vec2 v1, dot p2, vec2 v2)
{
	return (v2 / (p1 - p2)) / (v1 / v2) * v1.len();
}

dot ll2d(dot p1, vec2 v1, dot p2, vec2 v2)
{
	ld t = (v2 / (p1 - p2)) / (v1 / v2);
	dot I = p1 + (v1 * t);
	return I;
}

using poly = vector<dot>;

void CH(const poly& A, poly& Ach)
{
	int n = A.size();
	if (n <= 2) {
		Ach = A;
		return;
	}

	poly P = A;
	sort(P.begin(), P.end(), [](const dot& a, const dot& b) {
		return a.x < b.x || (a.x == b.x && a.y < b.y);
	});

	Ach.clear();
	for(int i = 0; i < n; i++)
	{
		while(Ach.size() >= 2 && ((Ach[Ach.size() - 1] - Ach[Ach.size() - 2]) / (P[i] - Ach[Ach.size() - 2])) <= 0)
			Ach.pop_back();
		Ach.push_back(P[i]);
	}
	size_t k = Ach.size();
	for(int i = n - 2; i >= 0; i--)
	{
		while(Ach.size() > k && ((Ach[Ach.size() - 1] - Ach[Ach.size() - 2]) / (P[i] - Ach[Ach.size() - 2])) <= 0)
			Ach.pop_back();
		Ach.push_back(P[i]);
	}
	Ach.pop_back();
}

ld S(const poly& A)
{
	int n = A.size();
	if(n < 3) return 0;
	ld area = 0;
	for(int i = 0; i < n; i++)
	{
		dot p = A[i], q = A[(i + 1) % n];
		area += p.x * q.y - p.y * q.x;
	}
	return fabsl(area) * 0.5;
}

//半平面
struct hplane
{
	dot p; vec2 dir;
	ld ang, c;
	hplane(const dot& _p, const vec2& _d): p(_p), dir(_d)
	{
		ang = atan2l(dir.y, dir.x);
		ld dlen = dir.len();
		c = (dlen > EPS ? (dir / p) / dlen : 0);
	}
	bool operator < (const hplane& b) const
	{
		if(fabsl(ang - b.ang) > EPS)
			return ang < b.ang;
		return c > b.c;
	}
	dot  operator / (hplane b) {return ll2d(p, dir, b.p, b.dir);}
};

// 判断点是否在半平面外
bool out(hplane h, dot pt)
{
	return (h.dir / (pt - h.p)) < -EPS;
}

bool inside(dot a, vec2 v, dot p)
{
	return (v / (p - a)) <= EPS;
}

bool has_kernel(const vector<dot>& P)
{
	int n = P.size();
	vector<pair<dot, vec2>> E(n);
	for(int i = 0; i < n; i++)
	{
		dot a = P[i], b = P[(i+1)%n];
		E[i] = {a, b - a};
	}
	const ld EPS = 1e-9L;
	

	for(int i = 0; i < n; i++)
	{
		bool ok = true;
		for(int j = 0; j < n; j++)
		{
			if(!inside(E[j].first, E[j].second, P[i]))
			{
				ok = false;
				break;
			}
		}
		if(ok) return true;
	}

	for(int i = 0; i < n; i++)
	{
		for(int j = i + 1; j < n; j++)
		{
			ld d = (E[i].second / E[j].second);
			if(fabsl(d) < EPS) continue;
			dot p = ll2d(E[i].first, E[i].second,
						 E[j].first, E[j].second);
			bool ok = true;
			for(int k = 0; k < n; k++)
			{
				if(!inside(E[k].first, E[k].second, p))
				{
					ok = false;
					break;
				}
			}
			if(ok) return true;
		}
	}
	return false;
}

int solve1()
{
	static int cnt = 1;
	int n; 
	if(scanf("%d", &n)!=1 || n == 0) return 0;
	vector<dot> P(n);
	for(int i = 0; i < n; i++) P[i].input();

	printf("Room #%d:\n", cnt++);
	if(has_kernel(P))
		printf("Surveillance is possible.\n\n");
	else
		printf("Surveillance is impossible.\n\n");
	return 1;
}


int main()
{
	int t = solve1();
	while(t)
		t = solve1();
	return 0;
}