package task

type Task interface {
	Execute() (string, error)
}
