#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::ostream;
using std::istream;
using std::endl;

class Ponto3d{
	private:
		friend ostream& operator<<(ostream &ostr, Ponto3d &op);

		int x;
		int y;
		int z;
		
	public:
		Ponto3d(int a, int b, int c) { x=a; y=b; z=c; };
		Ponto3d() { x = 0 ; y = 0; z = 0; };
		
		void operator=(Ponto3d P){
			x = P.x;
			y = P.y;
			z = P.z;
		}		
		
		Ponto3d operator+(Ponto3d P){
			Ponto3d holder;	
			holder.x = x + P.x;
			holder.y = y + P.y;
			holder.z = z + P.z;
			return holder;
		}
		
		Ponto3d operator-(Ponto3d P){
			Ponto3d holder;	
			holder.x = x - P.x;
			holder.y = y - P.y;
			holder.z = z - P.z;
			return holder;
		}
		
		float operator*(Ponto3d P){
			return std::sqrt(std::pow(P.x - x, 2) + std::pow(P.y - y, 2) + std::pow(P.z - z, 2));
		}
		
		bool operator==(Ponto3d P){
			if(x==P.x && y==P.y && z==P.z) return true;
			else return false;
		}
};

ostream& operator<<(ostream& ostr, Ponto3d &P){
	ostr << "(" << P.x << ", " << P.y << ", " << P.z << ")\n";
	return ostr;
}

float distancia(Ponto3d P1, Ponto3d P2){
	return P1 * P2;
}
