program loops
  implicit none
  ! TODO define parameters nx and ny
  ! TODO: define real-valued array A
  integer :: i, j
  integer, parameter :: nx = 20, ny = 10
  real :: a(0:nx+1, 0:ny+1)
  ! TODO initialize array A here
  a = 65.0
  !sides
  do i=0, nx+1
   a(i,0) = 20.0
   a(i, ny+1) = 85.0
  end do
  !up and down
  do j=0, ny+1
   a(0, j) = 70.0
   a(nx+1, j) = 5.0
  end do
  !--------------------------------------------------
  ! Print out the array
  ! the ':' syntax means the whole row, see the Fortran arrays lecture
  do i = 0, nx+1
     write(*, '(12F6.1)') a(i,:)
  end do

end program loops
