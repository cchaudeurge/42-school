#include "push_swap.h"

void	optimize_lis(t_sorter *sorter)
{
	int	initial_lis_len;

	find_longest_lis(sorter);
	initial_lis_len = sorter->lis_len;
	move(sorter, 1, swap, stack_a);
	find_longest_lis(sorter);
	if (sorter->lis_len <= initial_lis_len)
 	{
		move(sorter, 1, swap, stack_a);
		find_longest_lis(sorter);
	}
}

void	optimize_s_s(t_list *move_lst)
{
	t_move	*move;

	while (move_lst)
	{
		move = move_lst->content;
		if (move->operation == swap && move->count > 1)
			move->count = move->count % 2;
		move_lst = move_lst->next;
	}
}

void	optimize_r_rr(t_list *move_lst)
{
	t_move	*move1;
	t_move	*move2;

	while (move_lst && move_lst->next)
	{
		move1 = move_lst->content;
		move2 = move_lst->next->content;
		if (move1->operation + move2->operation == rotate + revrotate &&
			move1->stack == move2->stack && move1->count * move2->count != 0)
		{
			move1->count--;
			move2->count--;
		}
		move_lst = move_lst->next;
	}
}

void	optimize_pa_pb(t_list *move_lst)
{
	t_move	*move1;
	t_move	*move2;

	while (move_lst && move_lst->next)
	{
		move1 = move_lst->content;
		move2 = move_lst->next->content;
		if (move1->operation * move2->operation == 1 &&
			move1->stack != move2->stack && move1->count * move2->count != 0)
		{
			move1->count--;
			move2->count--;
		}
		move_lst = move_lst->next;
	}
}

void	optimize_ra_pa_rra(t_sorter *sorter, t_list *move_lst)
{
	t_move	*move1;
	t_move	*move2;
	t_move	*move3;
	t_list	*new_node;

	while (move_lst && move_lst->next && move_lst->next->next)
	{
		move1 = move_lst->content;
		move2 = move_lst->next->content;
		move3 = move_lst->next->next->content;
		if (move1->count * move2->count * move3->count != 0
			&& move1->operation == rotate && move1->stack == stack_a
			&& move2->operation == push && move2->stack == stack_a
			&& move3->operation == revrotate && move3->stack == stack_a)
		{
			move1->count--;
			move3->count--;
			new_node = create_move_node(sorter, 1, swap, stack_a);
			ft_lstadd_after_node(&move_lst->next, new_node);
		}
		move_lst = move_lst->next;
	}
}

