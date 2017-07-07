program arrays
  implicit none
  integer :: nx, ny
  integer :: i, alloc_stat
  ! TODO: define allocatable array A
  real, allocatable :: a(:,:)
  write (*,*) 'Give number of rows and columns for matrix A:'
  read (*,*) nx, ny

  ! TODO allocate A now that we know nx and ny
  allocate(a(0:nx+1, 0:ny+1), stat=alloc_stat)
  if (alloc_stat /= 0) call abort()

  ! TODO Use array syntax to initialize the array
  a =65.0
  a(:,0) = 20.0
  a(:,ny+1) = 85.0
  a(0, :) = 70.0
  a(nx+1, :) = 5.0


  !--------------------------------------------------
  ! Print out the array
  do i = 0, nx+1
    write(*,'(*(F6.1))') a(i,:)
  end do


end program arrays
