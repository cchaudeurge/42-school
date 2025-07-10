t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	**new_lst;
	t_list	*new_node;
	t_list	*original_node;

	if (!lst || !f || !del)
		return (NULL);
	*new_lst = ft_lstnew(f(lst->content));
	if (!*new_lst)
		return (NULL);
	original_node = lst;
	while (original_node->next)
	{
		original_node = original_node->next;
		new_node = ft_lstnew(f(original_node->content));
		if (!new_node)
		{
			ft_lstclear(new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(new_lst, new_node);
	}
	return (*new_lst);
}

