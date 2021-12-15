import { Variant } from "../components/Variant";

export const VariantsPage = () => {
    const variants = [
        {
            id: 1,
            name: "Вариант №1",
        },
        {
            id: 2,
            name: "Вариант №2",
        },
        {
            id: 3,
            name: "Вариант №3",
        },
        {
            id: 4,
            name: "Вариант №4",
        },
        {
            id: 5,
            name: "Вариант №5",
        },
    ];

    return (
        <div className="container">
            <ul class="collection">
                {variants.map((variant) => (
                    <Variant name={variant.name} id={variant.id} />
                ))}
            </ul>
        </div>
    );
};
