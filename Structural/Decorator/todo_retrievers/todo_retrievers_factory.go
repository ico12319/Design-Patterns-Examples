package todo_retrievers

import (
	"context"
	gql "github.com/I763039/Todo-List/internProject/graph/model"
	"github.com/I763039/Todo-List/internProject/todo_app_service/pkg/configuration"
	"github.com/I763039/Todo-List/internProject/todo_app_service/pkg/constants"
)

type statusConverter interface {
	ToStringStatus(status *gql.TodoStatus) string
}

type priorityConverter interface {
	ToStringPriority(priority *gql.Priority) string
}

// factory to dynamically build correct retriever, without nesting if else constructions
type factory struct {
	sConverter statusConverter
	pConverter priorityConverter
}

func NewTodoRetrieverFactory(sConverter statusConverter, pConverter priorityConverter) *factory {
	return &factory{sConverter: sConverter, pConverter: pConverter}
}

func (f *factory) CreateTodoRetriever(ctx context.Context, criteria *gql.TodosFilterInput) QueryParamsTodoRetrievers {
	configuration.C(ctx).Debug("creating todo correct todo retriever in factory")

	retriever := newAllTodosRetriever()

	if criteria != nil && criteria.Status != nil {
		status := f.sConverter.ToStringStatus(criteria.Status)

		retriever = newTodosByCriteriaRetriever(retriever, constants.STATUS, status)
	}

	if criteria != nil && criteria.Priority != nil {
		priority := f.pConverter.ToStringPriority(criteria.Priority)

		retriever = newTodosByCriteriaRetriever(retriever, constants.PRIORITY, priority)
	}

	return retriever
}
