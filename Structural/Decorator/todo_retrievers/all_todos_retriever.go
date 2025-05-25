package todo_retrievers

import (
	"context"
	"github.com/I763039/Todo-List/internProject/graph/constants"
	"github.com/I763039/Todo-List/internProject/todo_app_service/pkg/configuration"
	"net/url"
)

// abstract component!

type QueryParamsTodoRetrievers interface {
	DetermineCorrectQueryParams(ctx context.Context, serverAddress string) (string, error)
}

// concrete component!
type allTodosRetriever struct{}

func newAllTodosRetriever() QueryParamsTodoRetrievers {
	return &allTodosRetriever{}
}

func (a *allTodosRetriever) DetermineCorrectQueryParams(ctx context.Context, serverAddress string) (string, error) {
	configuration.C(ctx).Debugf("crafting correct query params in all todos retriever")

	u, err := url.Parse(serverAddress)

	if err != nil {
		configuration.C(ctx).Errorf("error when trying to parse url address in all todos retriever")
		return "", err
	}

	u.Path += constants.TODO_PATH

	return u.String(), nil
}
