import { useCallback, useEffect, useState } from "react";

const storageName = "userData";

export const useAuth = () => {
    const [name, setName] = useState("Иванов И.И.");
    const [userId, setUserId] = useState(null);
    const [role, setRole] = useState("ученик");

    const login = useCallback((name, id, role) => {
        setName(name);
        setUserId(id);
        setRole(role);

        localStorage.setItem(
            storageName,
            JSON.stringify({
                userId: id,
                name,
                role,
            }),
        );
    }, []);

    const logout = useCallback(() => {
        setName(null);
        setUserId(null);
        setRole(null)
        localStorage.removeItem(storageName);
    }, []);

    useEffect(() => {
        const data = JSON.parse(localStorage.getItem(storageName));

        if (data && data.userId) {
            login(data.name, data.userId, data.role);
        }
    }, [login]);

    return { login, logout, name, userId, role };
};
