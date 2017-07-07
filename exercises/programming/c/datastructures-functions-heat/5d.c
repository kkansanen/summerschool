#define NX 256
#define NY 256

#define DX 0.01
#define DY 0.01
	
typedef struct {
		
	int nx, ny;
	double dx, dy;
	double dx2;
	double dy2;
	double array[NX+2][NY+2];
		
		
} tempfield;
	
	
void initialize_field (tempfield *f, int nx, int ny, double dx, double dy){
	
	int i, j;
	
	f->nx = nx;
    f->ny = ny;
    f->dx = dx;
    f->dy = dy;
    f->dx2 = dx*dx;
    f->dy2 = dy*dy;
	
	for (i = 1; i < f->nx+1; i++) {
        for (j = 1; j < f->ny+1; j++) {
            f->array[i][j] = 0.0;
        }
    }
	
	// Initial conditions for left and right
    for (i = 0; i < f->nx+2; i++) {
        f->array[i][0] = 20.0;
        f->array[i][f->ny+1] = 70.0;
    }
    // up and down
    for (j = 0; j < f->ny+2; j++) {
        f->array[0][j] = 85.0;
        f->array[f->nx+1][j] = 5.0;
    }
}	
	
void laplacian (tempfield *f){
	
	int i, j;
	double laplacian[f->nx+2][f->ny+2];
	
	for (i=1; i<f->nx+1; i++){
		for (j=1; j<f->ny+1; j++){
			laplacian[i][j] = (f->array[i-1][j]-2 * f->array[i][j]+ f->array[i+1][j])/(f->dx2) + (f->array[i][j-1]-2 * f->array[i][j]+f->array[i][j+1])/(f->dy2);
		}
	}
	
/*	for (i = 1; i < f->nx + 1; i++){
        for (j = 1; j < f->ny + 1; j++){
            f->array[i][j] = laplacian[i][j];
		}
	}*/
}
	
int main(void){	

	tempfield f;
	initialize_field(&f, NX, NY, DX, DY);
	laplacian(&f);
	
	return 0;
}

