package todo_retrievers

import (
	"context"
	"github.com/I763039/Todo-List/internProject/todo_app_service/pkg/configuration"
	"net/url"
)

// concrete decorator
type todosByCriteriaRetriever struct {
	inner          QueryParamsTodoRetrievers
	condition      string
	conditionValue string
}

func newTodosByCriteriaRetriever(inner QueryParamsTodoRetrievers, condition string, conditionValue string) QueryParamsTodoRetrievers {
	return &todosByCriteriaRetriever{inner: inner, condition: condition, conditionValue: conditionValue}
}

func (t *todosByCriteriaRetriever) DetermineCorrectQueryParams(ctx context.Context, serverAddress string) (string, error) {
	configuration.C(ctx).Debugf("crafting correct query params in todos by criteria retriever")

	baseUrl, err := t.inner.DetermineCorrectQueryParams(ctx, serverAddress)
	if err != nil {
		configuration.C(ctx).Error("error when trying to determine query params in todos by criteria retriever")
		return "", err
	}

	u, err := url.Parse(baseUrl)
	if err != nil {
		configuration.C(ctx).Error("error when trying to parse query in todos by criteria retriever")
		return "", err
	}

	query := u.Query()
	query.Set(t.condition, t.conditionValue)
	u.RawQuery = query.Encode()

	return u.String(), nil
}
