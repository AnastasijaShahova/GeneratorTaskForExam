import { useCallback, useState } from "react";

export const useHttp = (setModal, setMessage) => {
    const [loading, setLoading] = useState(false);
    const [error, setError] = useState(null);
    // const [errorMessage, setErrorMessage] = useState("")
    

    const request = useCallback(
        async (url, method = "GET", body = null, headers = {}) => {
            setLoading(true);
            try {
                if (body) {
                    body = JSON.stringify(body);
                    headers["Content-Type"] = "text/plain";
                }
                const response = await fetch(url, {
                    method,
                    body,
                    headers,
                })

                const data = await response.json();

                if (!response) {
                    setModal(true)
                    setMessage(data.message)
                    setError(data.message);
                }
                setLoading(false);

                return data;
            } catch (err) {
                setLoading(false);
                setError(err.message);
                throw err;
            }
        },
        [],
    );

    const clearError = useCallback(() => setError(null), []);

    return { loading, request, error, clearError };
};
