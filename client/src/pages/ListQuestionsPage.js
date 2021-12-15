import { QuestionCard } from "../components/Question";

export const ListQuestionsPage = () => {
    const questions = [
        {
            id: 1,
            name: "Вопрос №1",
            answers: [
                {
                    id: 1,
                    name: "Ответ 1",
                },
                {
                    id: 2,
                    name: "Ответ 2",
                },
                {
                    id: 3,
                    name: "Ответ 3",
                },
                {
                    id: 4,
                    name: "Ответ 4",
                },
            ],
        },
        {
            id: 2,
            name: "Вопрос №2",
            answers: [
                {
                    id: 1,
                    name: "Ответ 1",
                },
                {
                    id: 2,
                    name: "Ответ 2",
                },
                {
                    id: 3,
                    name: "Ответ 3",
                },
                {
                    id: 4,
                    name: "Ответ 4",
                },
            ],
        },
        {
            id: 3,
            name: "Вопрос №3",
            answers: [
                {
                    id: 1,
                    name: "Ответ 1",
                },
                {
                    id: 2,
                    name: "Ответ 2",
                },
                {
                    id: 3,
                    name: "Ответ 3",
                },
                {
                    id: 4,
                    name: "Ответ 4",
                },
            ],
        },
    ];
    return (
        <div className="container">
            <h3 className="center-align" style={{ color: "white" }}>
                Вариант 1
            </h3>
            {questions.map((question) => (
                <QuestionCard name={question.name} answers={question.answers} />
            ))}
            <a
                class="waves-effect waves-light btn modal-trigger"
                href="#modal1"
            >
                Modal
            </a>

            <div id="modal1" className="modal">
                <div className="modal-content">
                    <h4>Modal Header</h4>
                    <p>A bunch of text</p>
                </div>
                <div className="modal-footer">
                    <a
                        href="#!"
                        className="modal-close waves-effect waves-green btn-flat"
                    >
                        Agree
                    </a>
                </div>
            </div>
        </div>
    );
};
