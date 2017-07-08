module laplacian_mod
  implicit none
  real, parameter :: dx = 0.01, dy = 0.01
  integer :: i, j
contains
  
  subroutine initialize(field0)
! TODO: implement a subroutine that initializes the input array
  implicit none
  real, intent(inout) :: field0(1:,1:)
  integer :: xy(2)
  xy = shape(field0)
  call random_number(field0)
  field0(:,1) = 20.0
  field0(:,xy(2)) = 85.0
  field0(1, :) = 70.0
  field0(xy(1), :) = 5.0
  end subroutine initialize
   
  subroutine laplacian(curr, prev)
! TODO: insert a subroutine that computes a laplacian of the
! array "prev" and returns it as an array "curr"
  implicit none
  real, intent(out) :: curr(1:,1:)
  real, intent(in) :: prev(1:,1:)
  real, parameter :: dx = 0.01, dy = 0.01
  integer :: xy(2), i, j
  xy = shape(prev)
   !curr = 0
   do j=2, xy(2)-1
   do i=2, xy(1)-1
     curr(i,j) = (prev(i-1,j) - 2*prev(i,j) + prev(i+1,j))/(dx**2) + (prev(i, j-1) - 2*prev(i,j) + prev(i,j+1))/(dy**2)
   end do
  end do
  end subroutine laplacian

  subroutine write_field(array)
! TODO: write a subroutine that prints "array" on screen
  implicit none
  real, intent(in) :: array(1:,1:)
  integer :: xy
  xy = size(array, 1)
  write(*,*) ' '
  do i = 1, xy
     write(*, '(*(G10.2))') array(i,:)
  end do
  write(*,*) ' '
  end subroutine write_field

end module laplacian_mod
