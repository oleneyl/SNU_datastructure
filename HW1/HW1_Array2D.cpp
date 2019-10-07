#include "HW1_Array2D.h"

Array2D::Array2D(int size){
	m_size = size;
	m_array = new int*[size];
	int i,j;
	for(i=0; i<size; i++){
		m_array[i] = new int[size];
		for(j=0;j<size;j++){
			m_array[i][j] = size * i + j + 1;
		}
	}
}

Array2D::~Array2D(){
	for(int i=0; i<m_size; i++){
		delete m_array[i];
	}
	delete m_array;
}

ostream& operator<< (ostream& os, const Array2D& arr){
	int i, j;
	int padding_size = 0;
	int ref_size = arr.m_size * arr.m_size;
	while(ref_size != 0){
		padding_size += 1;
		ref_size = ref_size / 10;
	}
	for(i=0; i<arr.m_size; i++){
		for(j=0; j<arr.m_size; j++){
			os << setw(padding_size) << arr.m_array[i][j];
			if(j != arr.m_size){
				os << ' ';
			}
		}
		os << '\n';
	}
	return os;
}

void Array2D::Swap(int* a, int* b){
	int temp=*a;
	*a=*b;
	*b=temp;
}

void Array2D::MoveRight(int r, int dist){
	int first = 0;
	int second = m_size;
	int j;
	int exact_dist = dist % m_size;
	if(exact_dist < 0){
		exact_dist += m_size;
	}
	int contract_dist;
	while(second != (first + 2 * exact_dist)){
		if(first + exact_dist < second - exact_dist){
			for(j=0; j<exact_dist; j++){
				Swap(m_array[r]+second-exact_dist+j, m_array[r]+first+j);
			}
			first += exact_dist;
		}else{
			contract_dist = second - first - exact_dist;
			for(j=0; j<contract_dist; j++){
				Swap(m_array[r]+first+j, m_array[r]+second-contract_dist+j);
			}
			second -= contract_dist;
			exact_dist -= contract_dist;
		}
	}
	for(j=0; j<exact_dist; j++){
		Swap(m_array[r]+first+j, m_array[r]+first+exact_dist+j);
	}
}

void Array2D::MoveLeft(int r, int dist){
	MoveRight(r, m_size-dist);
}

void Array2D::MoveDown(int r, int dist){
	int first = 0;
	int second = m_size;
	int j;
	int exact_dist = dist % m_size;
	if(exact_dist < 0){
		exact_dist += m_size;
	}
	int contract_dist;
	while(second != (first + 2 * exact_dist)){
		if(first + exact_dist < second - exact_dist){
			for(j=0; j<exact_dist; j++){
				Swap(m_array[second-exact_dist+j]+r, m_array[first+j]+r);
			}
			first += exact_dist;
		}else{
			contract_dist = second - first - exact_dist;
			for(j=0; j<contract_dist; j++){
				Swap(m_array[first + j]+r, m_array[second-contract_dist+j]+r);
			}
			second -= contract_dist;
			exact_dist -= contract_dist;
		}
	}
	for(j=0; j<exact_dist; j++){
		Swap(m_array[first+j]+r, m_array[first+exact_dist+j]+r);
	}
}

void Array2D::MoveUp(int r, int dist){
	MoveDown(r, -1 * dist);
}

void Array2D::MoveUpRight(int d, int dist){
	int i=0, j=0;

	// Exact movement size calculation
	int r_size = d + 1;
	int start_point_x, start_point_y;
	if(r_size > m_size){
		r_size = m_size * 2 - r_size;
		start_point_x = m_size - 1;
		start_point_y = d - m_size + 1;
	}else{
		start_point_x = d;
		start_point_y = 0;
	}
	int exact_dist = dist % r_size;
	if(exact_dist < 0){
		exact_dist += r_size;
	}
	int contract_dist;

	int first = 0;
	int second = r_size;	

	//cout << r_size << ' ' << exact_dist << ' ' << first << ' ' << second << ' ' << start_point_x << ' '<< start_point_y << endl;

	while(second != (first + 2 * exact_dist)){
		//cout << "Movement " << (first) << ' ' << (second-exact_dist) << endl;
		if(first + exact_dist < second - exact_dist){
			for(j=0; j<exact_dist; j++){
				Swap(m_array[start_point_x - (second-exact_dist+j)] + (start_point_y + (second-exact_dist+j)), 
				m_array[start_point_x - (first+j)] + (start_point_y + (first+j)));
			}
			first += exact_dist;
		}else{
			contract_dist = second - first - exact_dist;
			for(j=0; j<contract_dist; j++){
				Swap(m_array[start_point_x - (first+j)] + (start_point_y + (first+j)), 
					m_array[start_point_x - (second-contract_dist+j)] + (start_point_y + (second-contract_dist+j)));
			}
			second -= contract_dist;
			exact_dist -= contract_dist;
		}
	}
	for(j=0; j<exact_dist; j++){
		Swap(m_array[start_point_x - (first+j)] + start_point_y + (first+j), 
			m_array[start_point_x - (first+exact_dist+j)] + start_point_y + (first+exact_dist+j));
	}
}

void Array2D::MoveDownLeft(int d, int dist){
	MoveUpRight(d, -1*dist);
}

void Array2D::MoveDownRight(int d, int dist){
	int j;

	// Exact movement size calculation
	int r_size = d + 1;
	int start_point_x, start_point_y;
	if(r_size > m_size){
		r_size = m_size * 2 - r_size;
		start_point_x = 0;
		start_point_y = m_size - r_size;
	}else{
		start_point_x = m_size - r_size;
		start_point_y = 0;
	}
	int exact_dist = dist % r_size;
	if(exact_dist < 0){
		exact_dist += r_size;
	}
	int contract_dist;
	
	int first = 0;
	int second = r_size;	

	while(second != (first + 2 * exact_dist)){
		if(first + exact_dist < second - exact_dist){
			for(j=0; j<exact_dist; j++){
				Swap(m_array[start_point_x + (second-exact_dist+j)] + (start_point_y + (second-exact_dist+j)), 
				m_array[start_point_x + (first+j)] + (start_point_y + (first+j)));
			}
			first += exact_dist;
		}else{
			contract_dist = second - first - exact_dist;
			for(j=0; j<contract_dist; j++){
				Swap(m_array[start_point_x + (first+j)] + (start_point_y + (first+j)), 
					m_array[start_point_x + (second-contract_dist+j)] + (start_point_y + (second-contract_dist+j)));
			}
			second -= contract_dist;
			exact_dist -= contract_dist;
		}
	}
	for(j=0; j<exact_dist; j++){
		Swap(m_array[start_point_x + (first+j)] + start_point_y + (first+j), 
			m_array[start_point_x + (first+exact_dist+j)] + start_point_y + (first+exact_dist+j));
	}
}

void Array2D::MoveUpLeft(int d, int dist){
	MoveDownRight(d, -1*dist);
}
